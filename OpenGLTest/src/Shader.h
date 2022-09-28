#pragma once

#include <string>
#include <unordered_map>

class Shader
{
private:
	unsigned int m_RendererID;
	std::string m_VertShaderFilename;
	std::string m_FragShaderFilename;
	std::unordered_map<std::string, int> m_UniformLocationCache;

public:
	Shader(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);

private:
	std::string ReadFile(const std::string& filename);
	unsigned int CompileShader(unsigned int type, const std::string& code);
	unsigned int CreateShader();
	int GetUniformLocation(const std::string& name);
};
