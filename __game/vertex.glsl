#version 410

in vec3 vp;
in vec3 pos;
in vec3 cam_pos;

void main() {

	float width = 640;
	float height = 480;
	float near = 0.1;
	float far = 100;
	float fov = 66;
	float aspect = 4/3;
	float range = tan(fov*0.5)*near;

	float orthographic = - 2/ (far - near);
	float Sx = (2 * near) / (range * aspect + range * aspect);
	float Sy = near / range;
	float Sz = -(far + near) / (far - near);
	float Pz = -(2 * far * near) / (far - near);

	vec3 up = vec3(0, 0, 1);
    vec3 target = vec3(0, -1, 0);
    vec3 cam_roll = vec3(0, 0, 0);

    vec3 distance;
    distance.x = target.x - cam_roll.x;
    distance.y = target.y - cam_roll.y;
    distance.z = target.z - cam_roll.z;

    vec3 forward;
    float m = sqrt(distance.x * distance.x + distance.y * distance.y + distance.z * distance.z);

    forward.x = distance.x / m;
    forward.y = distance.y / m;
    forward.z = distance.z / m;

    vec3 right = cross(forward, up);

	mat4 model_to_world = mat4(
	   0, 0, 1, pos.x,
   	   0,-1, 0, pos.y,
   	   1, 0, 0, pos.z,
   	   0, 0, 0, 1
	);


    mat4 world_to_view_rotaion = mat4(
        right.x, right.y, right.z, 0,
        up.x, up.y, up.z, 0,
        -forward.x, -forward.y, -forward.z, 0,
        0, 0, 0, 1
    );

	mat4 world_to_view_translation = mat4(
		1, 0, 0, -cam_pos.x,
   		0, 1, 0, -cam_pos.y,
  	 	0, 0, 1, -cam_pos.z,
 	  	0, 0, 0, 1
	);

	mat4 view_to_perspective = mat4(
	    Sx, 0, 0, 0,
	    0, Sy, 0, 0,
	    0, 0, Sz, Pz,
	    0, 0, -1, 1
	);


	mat4 view_to_orthographic = mat4(
		1/width, 0, 0,      0,
		0, 1/height, 0,     0,
		0, 0, orthographic, Sz,
		0, 0, 0, 1
	);

	vec4 position = vec4(vp, 1);

	position = position * model_to_world;
	position = position * world_to_view_translation;
	position = position * world_to_view_rotaion;
	position = position * view_to_perspective;
	
	gl_Position = position;

}