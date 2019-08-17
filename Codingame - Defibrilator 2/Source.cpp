#include <iostream>
#include <string>
#include <cmath>


int main()
{
	std::string line = "1;Maison de la Prevention Sante;6 rue Maguelone 340000 Montpellier;;3,87952263361082;43,6071285339217";

	std::string LON = "3,879483";
	std::string LAT = "43,608177";

	size_t comaLON = LON.find(",");
	size_t comaLAT = LAT.find(',');

	LON.replace(comaLON, 1, 1, '.');
	LAT.replace(comaLAT, 1, 1, '.');


	std::cout << LON << " " << LAT << std::endl;;

	size_t id = line.find(";");
	size_t name = line.find(";", id + 1);
	size_t address = line.find(";", name + 1);
	size_t semicolon = line.find(";", address + 1);
	size_t longitude = line.find(";", semicolon + 1);
	size_t latitude = line.find(";", longitude + 1);

	char s_id = line[0];
	std::string s_name = line.substr(id + 1, name - id - 1);
	std::string s_address = line.substr(name + 1, address - name - 1);
	std::string s_semicolon = line.substr(address + 1, semicolon - address - 1);
	std::string s_longitude = line.substr(semicolon + 1, longitude - semicolon - 1);
	std::string s_latitude = line.substr(longitude + 1, latitude - longitude - 1);

	std::cout << "id: " << s_id << "\nname: " << s_name << "\naddress: " << s_address << "\nlongitude: " << s_longitude << std::endl;
	std::cout << "latitude: " << s_latitude << std::endl;

	size_t comaLon = s_longitude.find(",");
	size_t comaLat = s_latitude.find(",");

	s_longitude.replace(comaLon, 1, 1, '.');
	s_latitude.replace(comaLat, 1, 1, '.');

	float PI = 3.14159;

	double LonA = std::stod(LON) / 180 * PI;
	double LatA = std::stod(LAT) / 180 * PI;
	double LonB = std::stod(s_longitude) / 180 * PI;
	double LatB = std::stod(s_latitude) / 180 * PI;
	


	double x = (LonB - LonA) * cos((LatA + LatB) / 2);
	double y = LatB - LatA;
	double d = sqrt(x * x + y * y) * 6371;

	std::cout << d;

	return 0;
}