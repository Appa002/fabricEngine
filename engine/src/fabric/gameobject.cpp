#include <fabric/gameobject.hpp>


void fabric::GameObject::free()
{
	while (GameObject::attributes.size() > 1)
	{
		if (GameObject::attributes.at(GameObject::attributes.size() - 1).isValid()) {
			GameObject::attributes.erase(GameObject::attributes.end() - 1);
		}
	}
		

	for (auto handle : GameObject::dllHandles) {
		FreeLibrary(handle);
		handle = 0;
	}


	

}

fabric::GameObject::GameObject() {

	Attribute attr;
	attr.content = new int(0);
	attr.hash = typeid(int).hash_code();
	attr.name = "0$"; 

	GameObject::attributes.push_back(attr);
}

fabric::GameObject::~GameObject() {
	GameObject::removeAttribute<int>("");
	if (GameObject::attributes.size() > 0)
		std::cout << "Not all attributes have been removed" << std::endl;

}

std::vector<fabric::Attribute> fabric::GameObject::getAttributeVector()
{
	return *const_cast<const std::vector<Attribute>*>(&attributes);
}

fabric::Attribute fabric::GameObject::getAttribute(std::string name)
{
	for (unsigned int i = 0; i < GameObject::attributes.size(); i++) {
		if (GameObject::attributes.at(i).name == name) {
			return GameObject::attributes.at(i);
		}
	}


	return GameObject::getAttribute("");
}

int fabric::GameObject::render(){
	VertexAttributeObject vao = GameObject::mesh.getVertexAttributeObject();

	// transform attribute sync
	bool error = false; 
	Attribute attrib = findAttribute<vec3>("transform", &error, 0);
	vec3* content;

	if (!error)
		content = reinterpret_cast<vec3*>(attrib.content);
	else {
		content = new vec3();
		content->x = 0;
		content->y = 0;
		content->z = 0;
	}
	VertexBufferObject vbo = VertexBufferObject(true, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
	
	std::vector<GLdouble> myPoints;


	// Super dumm solution from past me.
	for (unsigned int i = 0; i < GameObject::mesh.getData().size(); i++) {
		myPoints.push_back(content->x);
		myPoints.push_back(content->y);
		myPoints.push_back(content->z);
	}

	
	vbo.make<GLdouble>(myPoints);

	
	vao.enableAttribArray(1);
	vao.setVertexAtrrib(1, 3, vbo);
	// ! transform attribute sync


	// cam position sync

	vbo = VertexBufferObject(true, GL_ARRAY_BUFFER, GL_STATIC_DRAW);
	vec3 campPos = DataCore::get()->camPos;
	myPoints = std::vector<GLdouble>();


	for (unsigned int i = 0; i < GameObject::mesh.getData().size(); i++) {
		myPoints.push_back(campPos.x);
		myPoints.push_back(campPos.y);
		myPoints.push_back(campPos.z);
	}

	vbo.make<GLdouble>(myPoints);
	vao.enableAttribArray(2);
	vao.setVertexAtrrib(2, 3, vbo);

	// ! cam position sync

	glDisable(GL_CULL_FACE);
	glBindVertexArray(vao.handle);

	glDrawArrays(GL_POINTS, 0, this->mesh.getData().size() / 3);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, this->mesh.getData().size() / 3);

	

	//glDrawArrays(GL_P, 0, GameObject::mesh.getData().size());

	return 0;
}

int fabric::GameObject::setMesh(Mesh _mesh) {
	GameObject::mesh = _mesh;
	return 0;
}


std::string fabric::GameObject::removeNameMangling(std::string name)
{

	bool mangled = false;
	// 1. Check if name is mangled
	for (size_t i = 0; i <= 4; i++) {
		if (i < name.size()) {
			if (name[i] == '$') {
				mangled = true;
				break;
			}
				
		}
		
	}

	if (!mangled)
		return name;

	// 2. Remove any mangeling
	while (true) {
		if (name[0] != '$')
			name.erase(name.begin());
		else {
			name.erase(name.begin());
			return name;
		}
	}
}