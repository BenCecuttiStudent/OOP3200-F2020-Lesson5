#include <iomanip>
#include <iostream>
#include <vector>

#include "Vector2D.h"
#include "GameObject.h"

static void BuildGameObjects(std::vector<GameObject>& game_objects, int num = 2)
{
	Vector2D point;
	int id;
	for(int count = 0; count < num; count++)
	{
		
		std::cout << "Enter Game Object ID: ";
		std::cin >> id;
		std::cout << "Enter point coordinates (x, y): ";
		std::cin >> point;
		std::cout << "\n--------------------------------------------------------------" << std::endl;
		std::cout << "You Entered " << id << " for the game object's ID";
		std::cout << "You Entered " << point << " for the game object's position" << std::endl;
		std::cout << "--------------------------------------------------------------\n" << std::endl;
		auto* gameObject = new GameObject(id, point);
		game_objects.push_back(*gameObject);
	}
}

static void CompareGameObjects(const GameObject& object1, const GameObject& object2)
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Magnitude of first game object is: " << object1.GetPosition().GetMagnitude() << std::endl;
	std::cout << "Magnitude of second game object is: " << object2.GetPosition().GetMagnitude() << std::endl;
	std::cout << "Distance between first point and second point is: " << Vector2D::Distance(object1.GetPosition(), object2.GetPosition()) << std::endl;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	std::cout << "The angle (in degrees) from the first game object to the second game object is: " << Vector2D::SignedAngle(object1.GetPosition(), object2.GetPosition()) << std::endl;

	std::cout << "First Game Object Details: " << std::endl;
	std::cout << object1.ToString() << std::endl;
	std::cout << "Second Game Object Details: " << std::endl;
	std::cout << object2.ToString() << std::endl;
}


int main()
{
	std::vector<GameObject> gameObjects;

	
	int num_of_GO;

	std::cout << "How many game objects do you want to create?:";
	std::cin >> num_of_GO;

	BuildGameObjects(gameObjects, num_of_GO);

	int index1;
	std::cout << "What is the First Object index?: ";
	std::cin >> index1;
	std::cout << "--------------------------------------------------------------\n" << std::endl;
	int index2;
	std::cout << "What is the Second Object index?: ";
	std::cin >> index2;
	std::cout << "--------------------------------------------------------------\n" << std::endl;

	CompareGameObjects(gameObjects[index1], gameObjects[index2]);
	
}