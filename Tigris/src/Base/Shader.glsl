#Vertex
#version 330 core
layout (location=0) in vec4 aPos;
layout (location=1) in vec4 aColor;
layout (location=2) in float aTextureIndex;
layout (location=3) in vec2 aTextureCoords;

out vec4 uColor;
out vec2 uTextureCoords;
out float uTextureIndex;
uniform mat4 u_ViewMatrix;
float t =0.0f;
void main()
{
gl_Position = u_ViewMatrix*aPos;


uColor = aColor;
uTextureCoords = aTextureCoords;
uTextureIndex = aTextureIndex;
};

#Fragment
#version 330 core
out vec4 FragColor;
in vec4 uColor;
in vec2 uTextureCoords;
in float uTextureIndex;
uniform sampler2D uTextures[32];
void main()
{
//FragColor = texture(uTextures[int(uTextureIndex)],uTextureCoords) * uColor;
vec4 texColor = uColor;
	switch(int(uTextureIndex))
	{
		case 0: texColor *= texture(uTextures[0], uTextureCoords); break;
		case 1: texColor *= texture(uTextures[1], uTextureCoords); break;
		case 2: texColor *= texture(uTextures[2], uTextureCoords); break;
		case 3: texColor *= texture(uTextures[3], uTextureCoords); break;
		case 4: texColor *= texture(uTextures[4], uTextureCoords); break;
		case 5: texColor *= texture(uTextures[5], uTextureCoords); break;
		case 6: texColor *= texture(uTextures[6], uTextureCoords); break;
		case 7: texColor *= texture(uTextures[7], uTextureCoords); break;
		case 8: texColor *= texture(uTextures[8], uTextureCoords); break;
		case 9: texColor *= texture(uTextures[9], uTextureCoords); break;
		case 10: texColor *= texture(uTextures[10], uTextureCoords); break;
		case 11: texColor *= texture(uTextures[11], uTextureCoords); break;
		case 12: texColor *= texture(uTextures[12], uTextureCoords); break;
		case 13: texColor *= texture(uTextures[13], uTextureCoords); break;
		case 14: texColor *= texture(uTextures[14], uTextureCoords); break;
		case 15: texColor *= texture(uTextures[15], uTextureCoords); break;
		case 16: texColor *= texture(uTextures[16], uTextureCoords); break;
		case 17: texColor *= texture(uTextures[17], uTextureCoords); break;
		case 18: texColor *= texture(uTextures[18], uTextureCoords); break;
		case 19: texColor *= texture(uTextures[19], uTextureCoords); break;
		case 20: texColor *= texture(uTextures[20], uTextureCoords); break;
		case 21: texColor *= texture(uTextures[21], uTextureCoords); break;
		case 22: texColor *= texture(uTextures[22], uTextureCoords); break;
		case 23: texColor *= texture(uTextures[23], uTextureCoords); break;
		case 24: texColor *= texture(uTextures[24], uTextureCoords); break;
		case 25: texColor *= texture(uTextures[25], uTextureCoords); break;
		case 26: texColor *= texture(uTextures[26], uTextureCoords); break;
		case 27: texColor *= texture(uTextures[27], uTextureCoords); break;
		case 28: texColor *= texture(uTextures[28], uTextureCoords); break;
		case 29: texColor *= texture(uTextures[29], uTextureCoords); break;
		case 30: texColor *= texture(uTextures[30], uTextureCoords); break;
		case 31: texColor *= texture(uTextures[31], uTextureCoords); break;
	}
	FragColor = texColor;

};

