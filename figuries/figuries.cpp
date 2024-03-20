#include <iostream>
#include <fstream>
#include <string>

class Shape
{
public:
    virtual void Show() const = 0;
    virtual void Save(const std::string& filename) const = 0;
    virtual void Load(const std::string& filename) = 0;
    virtual ~Shape() {} 
};

class Square : public Shape 
{
private:
    double x, y; 
    double sideLength; 

public:
    Square(double x, double y, double sideLength) : x(x), y(y), sideLength(sideLength) {}

    void Show() const override 
    {
        std::cout << "Square: Top-left corner (" << x << ", " << y << "), Side length: " << sideLength << std::endl;
    }

    void Save(const std::string& filename) const override 
    {
        std::ofstream file(filename);
        if (file.is_open()) 
        {
            file << "Square\n";
            file << x << " " << y << " " << sideLength << std::endl;
            file.close();
        }
        else 
        {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }

    void Load(const std::string& filename) override 
    {
        std::ifstream file(filename);
        if (file.is_open()) 
        {
            std::string shapeType;
            file >> shapeType;
            if (shapeType == "Square") 
            {
                file >> x >> y >> sideLength;
            }
            else 
            {
                std::cerr << "Invalid shape type." << std::endl;
            }
            file.close();
        }
        else 
        {
            std::cerr << "Unable to open file: " << filename << std::endl;
        }
    }
};



int main() {
    Square square(1.0, 2.0, 5.0);
    square.Show();
    square.Save("square.txt");

    Square square2(0, 0, 0); 
    square2.Load("square.txt");
    square2.Show();

    return 0;
}

