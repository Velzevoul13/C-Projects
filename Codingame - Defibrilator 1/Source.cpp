#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>


struct GeoData
{
	double latitute;
	double longitude;

	GeoData() { latitute = 0; longitude = 0; }

	GeoData(std::string s_latitude, std::string s_longitude)
	{
		int pos = s_latitude.find(',');
		s_latitude[pos] = '.';
		pos = s_longitude.find(',');
		s_longitude[pos] = '.';
		latitute = std::stod(s_latitude);
		longitude = std::stod(s_longitude);
	}

	static double DistanceCalculation(const GeoData& A, const GeoData& B) 
	{
		const int factor = 6371;
		double x = (B.longitude - A.longitude) * cos((A.latitute + B.latitute) / 2);
		double y = B.latitute - A.latitute;
		double d = sqrt((x * x) + (y * y)) * factor;
		return d;
	}
	
};




struct Defib
{
	std::string id, name, address;
	GeoData location;

	Defib(std::string description);

};

Defib::Defib(std::string description)
{
	std::vector<std::string> description_field;
	std::stringstream input(description);
	std::string sector;

	while (std::getline(input, sector, ';'))
	{
		description_field.push_back(sector);
	}

	id = description_field[0];
	name = description_field[1];
	address = description_field[2];

	std::string longitude = description_field[3];
	std::string latitude = description_field[4];
	GeoData descibed_place(latitude, longitude);
	location = descibed_place;
}


int main()
{

	std::string LON = "3,879483";
	std::string LAT = "43,608177";
	GeoData current_location(LAT, LON);

	int N = 3;
	std::string DEFIB1 = "1;Maison de la Prevention Sante;6 rue Maguelone 340000 Montpellier;;3,87952263361082;43,6071285339217";
	std::string DEFIB2 = "2;Hotel de Ville;1 place Georges Freche 34267 Montpellier;;3,89652239197876;43,5987299452849";
	std::string DEFIB3 = "3;Zoo de Lunaret;50 avenue Agropolis 34090 Mtp;;3,87388031141133;43,6395872778854";
	
	std::vector<Defib> vec;

	vec.push_back(Defib(DEFIB1));
	vec.push_back(Defib(DEFIB2));
	vec.push_back(Defib(DEFIB3));

	double closest = -1;
	std::string closest_name;

	for (int i = 0; i < N; ++i)
	{
		double distance = GeoData::DistanceCalculation(current_location, vec[i].location);
		if (closest == -1 || distance < closest)
		{
			closest = distance;
			closest_name = vec[i].name;
		}

	}

	std::cout << closest_name << std::endl;
	

	return 0;
}