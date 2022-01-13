#version 330

in vec2 fragTexCoord;
in vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

// Output fragment color
out vec4 finalColor;

void main()
{
    // Texel color fetching from texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord)*colDiffuse*fragColor;
    
    // Calculate final fragment color
	if(texelColor.a < 0.1) {
		finalColor = texelColor;
	} else {
		finalColor = mix (
				vec4(0, .08, .025, 1),
				texelColor,
				min(gl_FragCoord.w / gl_FragCoord.z, 1.0));
	}
}
