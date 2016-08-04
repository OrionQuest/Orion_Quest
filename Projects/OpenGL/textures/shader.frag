#version 330 core
in vec3 our_color;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D our_texture;

void main()
{
    color=texture(our_texture,TexCoord)*vec4(our_color,1.0f);
}
