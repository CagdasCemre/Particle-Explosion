#ifndef PARTICLE_H
#define PARTICLE_H

namespace fundamentals{

class Particle
{

    public:
        double m_x;
        double m_y;
        //double m_xspeed;
        //double m_yspeed;
    private:
        double m_speed;
        double m_direction;

    private:
        void init();

    public:
        Particle();
        virtual ~Particle();
        void update(int interval);




};


}//namespace


#endif // PARTICLE_H
