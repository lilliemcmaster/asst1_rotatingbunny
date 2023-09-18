#include "Animation.h"

Animation::Animation() {
	this->m_model_mat = glm::mat4(1.0f);
}

Animation::~Animation() {
}

void Animation::init() {
	reset();
}

	//////////
	// Task 5: Reset
	// Have a “Reset” button that can reset the bunny to the initial state
void Animation::reset() {
	m_model_mat = glm::mat4(1.0f);
	m_model_mat = glm::translate(m_model_mat, glm::vec3(5.0, 0.0, 0.0));
}

void Animation::update(float delta_time) {
	//////////
	// Task 3: implement the update function for rotation
	//implemented with a more OO approach- see rotateX(angle) and rotateY(angle)
}

	//////////
	// Task 3: implement the update function for rotation
void Animation::rotateX(float angle) {
	m_model_mat = glm::rotate(m_model_mat, glm::radians(angle), glm::vec3(1.0,0.0,0.0));
}

void Animation::rotateY(float angle){
	//rotate the bunny angle degress on the y axis
	if (angle != 0){
		//do translation first
		m_model_mat = glm::translate(m_model_mat, glm::vec3(-5.0, 0.0, 0.0));
		//then do model matrix rotation multiplication
		m_model_mat = glm::rotate(m_model_mat, glm::radians(angle), glm::vec3(0.0, 1.0, 0.0));
		//translate back
		m_model_mat = glm::translate(m_model_mat, glm::vec3(5 * sin(angle* M_PI / 180), 0.0,0.0));
	}
}
