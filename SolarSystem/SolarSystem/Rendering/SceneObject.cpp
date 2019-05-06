﻿#include "Rendering.h"

Transform* SceneObject::GetTransform()
{
	return &transfom;
}

void SceneObject::SetMaterial(Material* material)
{
	this->material = material;
}

Material* SceneObject::GetMaterial()
{
	return material;
}


void SceneObject::SetMesh(Mesh* mesh)
{
	this->mesh = mesh;
}

Mesh* SceneObject::GetMesh()
{
	return mesh;
}

void SceneObject::SetViewMatrix(glm::mat4 view)
{
	material->GetShader()->Use();
	material->SetMatrix("view", view);
}

void SceneObject::SetProjectionMatrix(glm::mat4 projection)
{
	material->GetShader()->Use();
	material->SetMatrix("projection", projection);
}

void SceneObject::SetVector(const char* uniformName, GLfloat x, GLfloat y)
{
	material->GetShader()->Use();
	glUniform2f(glGetUniformLocation(material->GetShader()->GetProgramId(), uniformName), x, y);
}

void SceneObject::SetVector(const char* uniformName, GLfloat x, GLfloat y, GLfloat z)
{
	material->GetShader()->Use();
	glUniform3f(glGetUniformLocation(material->GetShader()->GetProgramId(), uniformName), x, y, z);
}


void SceneObject::Draw()
{
	material->Use();
	material->SetMatrix("model", transfom.GetModelMatrix());
	mesh->BindVertexArray();
	glDrawElements(GL_TRIANGLES, mesh->GetIndicesCount(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	material->Unbind();
}
