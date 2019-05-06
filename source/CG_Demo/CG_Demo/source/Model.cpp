#include "Model.h"



Model::Model()
{
	file = fopen("assets/campus.obj", "r");
}


Model::~Model()
{
}

void Model::readOBJ() {

	if (file == NULL) {
		printf("algo anda mal");
		return;
	}
	char header[1000];
	while (!fscanf(file, "%s", header) != EOF) {
		if (!strcmp(header, "v")) {
			vec3 _v;
			fscanf(file, "%f %f %f\n", &_v.x, &_v.y, &_v.z);
			v.push_back(_v);
			printf("%d %d %d", v[v.size() - 1].x, v[v.size() - 1].y, v[v.size() - 1].z);
		}
		else if (!strcmp(header, "vt")) {
			vec2 _vt;
			fscanf(file, "%f %f\n", &_vt.x, &_vt.y);
			vt.push_back(_vt);
		}
		else if (!strcmp(header, "vn")) {
			vec3 _vn;
			fscanf(file, "%f %f %f\n", &_vn.x, &_vn.y, &_vn.z);
			vn.push_back(_vn);
		}
		else if(!strcmp(header, "f")) {
			point p;
			for (int i = 0; i < 3; i++) {
				fscanf(file, "%d/%d/%d", &p.p[i].x, &p,&p.p[i].y, &p.p[i].z);
				
			}
			points.push_back(p);
		}
		
	}
}

void Model::load() {
	
}

