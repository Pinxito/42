/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguillen <gguillen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 02:55:22 by gguillen          #+#    #+#             */
/*   Updated: 2026/08/09 02:57:33 by gguillen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
 
int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "The program takes in argument a filename and 2 strings" << std::endl;
		return (1);
	}
 
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
 
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty." << std::endl;
		return (1);
	}
 
	std::ifstream file(filename.c_str());
	if (!file)
	{
		std::cerr << "Impossible to load the file." << std::endl;
		return (1);
	}
 
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile)
	{
		std::cerr << "Impossible to create the new file." << std::endl;
		file.close();
		return (1);
	}
 
	std::string line;
	std::string newLine;
	while (std::getline(file, line))
	{
		newLine.clear();
		size_t pos = 0;
		size_t index = line.find(s1);
 
		while (index != std::string::npos) // si les valeurs sont differentes ca veut dire au une sous chaine a ete trouvee.
		{
			newLine += line.substr(pos, index - pos); // ce qu'il y a avant s1
			newLine += s2;                             // on insere s2 a la place
			pos = index + s1.length();                 // on avance apres s1
			index = line.find(s1, pos);
		}
		newLine += line.substr(pos); // ce qu'il reste apres la derniere occurrence
 
		outputFile << newLine << std::endl;
	}
 
	file.close();
	outputFile.close();
	return (0);
}