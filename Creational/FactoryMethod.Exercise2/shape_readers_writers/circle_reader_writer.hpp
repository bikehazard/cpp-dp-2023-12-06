#ifndef CIRCLEREADERWRITER_H
#define CIRCLEREADERWRITER_H

#include "../circle.hpp"
#include "shape_reader_writer.hpp"

namespace Drawing
{
    namespace IO
    {
        class CircleReaderWriter : public ShapeReaderWriter
        {
        public:
            void read(Shape& shp, std::istream& in) override
            {
                Circle& circle = dynamic_cast<Circle&>(shp);
                Point pt;
                int r;
                in >> pt >> r;
                circle.set_coord(pt);
                circle.set_radius(r);
            }

            void write(const Shape& shp, std::ostream& out) override
            {
                const Circle& circle = dynamic_cast<const Circle&>(shp);
                out << Circle::id << " " << circle.coord().x << " " << circle.coord().y << " " << circle.radius() << "\n";
            }
        };
    }
}

#endif // CIRCLEREADERWRITER_H
