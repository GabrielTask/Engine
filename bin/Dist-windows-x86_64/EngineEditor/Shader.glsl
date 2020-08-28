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
FragColor = texture(uTextures[int(uTextureIndex)],uTextureCoords) * uColor;
};

