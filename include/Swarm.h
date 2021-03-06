#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace fundamentals{

class Swarm
{
public:
        const static int NPARTICLES =  5000;

    private:
        int lastTime;
        Particle *m_pParticles;

    public:
        Swarm();
        virtual ~Swarm();
        void update(int elapsed);

        const Particle * const getParticles(){ return m_pParticles; };

    protected:

    private:
};

}


#endif // SWARM_H
