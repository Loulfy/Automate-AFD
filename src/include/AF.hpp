#ifndef AF_H
#define AF_H

#include <iostream>
#include <vector>
#include <set>
#include <fstream>

#include "Automate.hpp"

class AF : public Automate
{
	public:

		AF();
		void draw() override;
		bool loadFromFile(std::string filePath);
		void deupsilonisation();
		
		std::set<int> initiaux();
		std::set<int> terminaux();
		std::vector<std::vector<std::set<int>>> transitions();

	private:

		int m_etats;
		std::set<int> m_initiaux;
		std::set<int> m_terminaux;
		std::vector<std::vector<std::set<int>>> m_transitions;

};

std::vector<std::string> split(std::string line);

#endif
