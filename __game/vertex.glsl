#version 410

in vec3 vp;
in vec3 pos;
in vec3 cam_pos;

void main() {

	float near = 0.1;
	float far = 100;
	float fov = 66;
	float aspect = 4/3;
	float range = tan(fov*0.5)*near;

	float Sx = (2 * near) / (range * aspect + range * aspect);
	float Sy = near / range;
	float Sz = -(far + near) / (far - near);
	float Pz = -(2 * far * near) / (far - near);
	

	mat4 model_to_world = mat4(
	   0, 0, 1, pos.x,
   	   0, -1,0, pos.y,
   	   1, 0, 0, pos.z,
   	   0, 0, 0, 1
	);

	mat4 world_to_view = mat4(
	   	0, 0, 1, -cam_pos.x,
   		0,-1, 0, -cam_pos.y,
   		1, 0, 0, -cam_pos.z,
   		0, 0, 0, 1
	);

	mat4 view_to_perspective = mat4(
	    Sx, 0, 0, 0,
	    0, Sy, 0, 0,
	    0, 0, Sz, Pz,
	    0, 0, -1, 0
	);

	vec4 position = vec4(vp, 1);

	position = position * model_to_world;
	position = position * world_to_view;
	position = position * view_to_perspective;	
	


	gl_Position = position;

}