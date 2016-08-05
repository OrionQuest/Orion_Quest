#version 330 core
in vec3 our_color;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D our_texture1;
uniform sampler2D our_texture2;

void main()
{
    color=mix(texture(our_texture1,TexCoord),texture(our_texture2,vec2(1.0f-TexCoord.x,TexCoord.y)),0.2);
}
