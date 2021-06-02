
#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#define BOOST_SPIRIT_THREADSAFE

using boost::property_tree::ptree;
using namespace std;

int main() {
    const std::string json_str = "{\"click\": 10, \"imagesum\": 5, \"commentsum\": 20}";
    std::istringstream iss;
    iss.str(json_str.c_str());
    boost::property_tree::ptree parser;
    boost::property_tree::json_parser::read_json(iss, parser);

    int click = 0;
    int imagesum = 0;
    int commentsum = 0;
    int nokey = 0;

    ptree::const_assoc_iterator it = parser.find("nokey");
    if(it != parser.not_found()) {
        nokey = parser.get<int>("nokey");
    }

    it = parser.find("click");
    if(it != parser.not_found()) {
        click = parser.get<int>("click");
    }

    it = parser.find("imagesum");
    if(it != parser.not_found()) {
        imagesum = parser.get<int>("imagesum");
    }

    it = parser.find("commentsum");
    if(it != parser.not_found()) {
        commentsum = parser.get<int>("commentsum");
    }

    cout << "click: " << click << std::endl;
    cout << "imagesum: " << imagesum << std::endl;
    cout << "nokey: " << nokey << std::endl;
    cout << "commentsum: " << commentsum << std::endl;

}


