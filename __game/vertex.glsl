#version 410

in vec3 vp;
in vec3 pos;
in vec3 cam_pos;

void main() {

	mat4 model_to_world = mat4(
	   	1, 0, 0, pos.x,
   		0, 1, 0, pos.y,
   		0, 0, 1, pos.z,
   		0, 0, 0, 1
	);

	mat4 world_to_cam = mat4(
	   	1, 0, 0, -cam_pos.x,
   		0, 1, 0, -cam_pos.y,
   		0, 0, 1, -cam_pos.z,
   		0, 0, 0, 1
	);

	vec4 position = vec4(vp, 1) * model_to_world;
	position = position * world_to_cam;


	gl_Position = position;

}