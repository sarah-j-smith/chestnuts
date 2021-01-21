#include <iostream>
#include <istream>
#include <optional>
#include <unordered_set>
#include <vector>
#include <deque>
#include <sstream>
#include <functional>

#ifdef _DEBUG
void debug( std::function<void (void)> message ) {
    message();
}
#else
void debug( std::function<void (void)> ) {
    // do nothing
}
#endif

struct CityLink {
    std::string src;
    std::string dest;
    
    CityLink(const std::string &s, const std::string &d) : src(s), dest(d) {}
    
    /**
     * Find the neighbour that the given name is connected to by this route, if the given
     * name is one of the endpoints of this route; or nullopt if it is not
     */
    std::optional<std::string> getNeighbour(const std::string &nm) const
    {
        if (src == nm)
        {
            return dest;
        }
        else if (dest == nm)
        {
            return src;
        }
        return std::nullopt;
    }
    
    CityLink reversed() const
    {
        return CityLink(dest, src);
    }
};

struct CityLinkHasher {
    size_t operator()(CityLink const &s) const
    {
        return std::hash<std::string>{}(s.src + "|" + s.dest);
    }
};

struct CityLinkComparator {
    bool operator()(const CityLink &lhs, const CityLink &rhs) const
    {
        return lhs.src == rhs.src && lhs.dest == rhs.dest;
    }
};

using Graph = std::unordered_set<CityLink, CityLinkHasher, CityLinkComparator>;

bool isRouteInGraph(const Graph &graph, std::string src, std::string dest)
{
    return graph.count(CityLink(src, dest)) > 0 || graph.count(CityLink(dest, src)) > 0;
}

/**
 * Returns the sub-strings within the given input_values seperated by a comma.
 */
std::vector<std::string> componentsSeperatedByComma(std::string input_values)
{
    auto components = std::vector<std::string>();
    std::stringstream input_stream(input_values);
    std::string buf;
    while (std::getline(input_stream, buf, ','))
    {
        components.push_back(buf);
    }
    return components;
}

/**
 * Returns true if there is a path from src to dest in graph
 */
bool path_search(Graph graph, std::string src, std::string dest)
{
    
    // Trivial case exit
    if (isRouteInGraph(graph, src, dest))
    {
        return true;
    }
    
    auto verts = std::deque<std::string>() = {src};
    auto visited = std::unordered_set<std::string>();
    while (verts.size() > 0)
    {
        auto it = verts.front();
        verts.pop_front();
        for (const CityLink &r : graph)
        {
            auto nghbr = r.getNeighbour(it);
            if (nghbr && *nghbr == dest)
            {
                return true;
            }
            else
            {
                if (!visited.count(*nghbr))
                {
                    verts.push_back(*nghbr);
                }
            }
        }
        visited.insert(it);
    }
    return false;
}

int expectedGraphSize = 0;
auto cityLinks = Graph();

const char *NO_PATH_FOUND = "false";
const char *FOUND_PATH = "true";

bool got_result = false;

int main(int argc, char *argv[])
{
    std::string input_values;

    debug([](){ std::cout << "Graph span - debug" << std::endl; });
    
    while (std::getline(std::cin, input_values))
    {
        if (expectedGraphSize == 0)
        {
            // expecting an int for the size of the graph - throw here if its not an int
            expectedGraphSize = stoi(input_values);
            if (expectedGraphSize == 0)
            {
                std::cout << NO_PATH_FOUND << std::endl;
                break;
            }
            debug([](){ std::cout << "Expecting " << expectedGraphSize << " edges" <<  std::endl; });
        }
        else
        {
            auto cities = componentsSeperatedByComma(input_values);
            if (cities.size() == 2)
            {
                auto newCityRoute = CityLink(cities[0], cities[1]);
                if (cityLinks.size() >= expectedGraphSize)
                {
                    // process route request
                    debug([cities](){
                        got_result = true;
                        std::cout << "Searching graph with " <<  cityLinks.size() << " elements" <<  std::endl;
                        std::cout << "     requested route: " <<  cities[0] << " -> " << cities[1] << " exists..." << std::endl;
                    });
    
                    auto result = path_search(cityLinks, newCityRoute.src, newCityRoute.dest);
                    std::cout << (result ? FOUND_PATH : NO_PATH_FOUND) << std::endl;
                    break;
                } else {
                    if (cityLinks.count(newCityRoute) == 0 &&
                        cityLinks.count(newCityRoute.reversed()) == 0)
                    {
                        debug([cities](){
                            std::cout << "\tadding route " << cityLinks.size() << " : " <<  cities[0] << " -> " << cities[1] << std::endl;
                        });
                        cityLinks.insert(newCityRoute);
                    } else {
                        debug([cities](){
                            std::cout << "\tignoring duplicate route : " <<  cities[0] << " -> " << cities[1] << std::endl;
                        });
                    }
                }
            } else {
                debug([input_values](){ std::cout << "     Could not parse route : \"" <<  input_values << "\"" << std::endl; });
            }
        }
    }
    debug([]() {
        if (cityLinks.size() != expectedGraphSize)
        {
            std::cout << "Graph had " << cityLinks.size() << " elements; expected " << expectedGraphSize << std::endl;
        }
    });
}
