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
		void toDeterminist();

	private:

		int m_etats;
		std::vector<int> m_initiaux;
		std::vector<int> m_terminaux;
		std::vector<std::vector<std::set<int>>> m_transitions;

		void deupsilonisation();

};

std::vector<std::string> split(std::string line);

#endif
