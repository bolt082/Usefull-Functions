#include <bits/stdc++.h>
using namespace std;

#define V vector
#define pb push_back

template<class datatype> struct Edge{
    datatype src, dest;
    double weight;
};

template<class datatype> class Graph
{
    public:
        int v, e;
        V<datatype> vx;
        V< Edge<datatype> > eg;
        void setup(int v, int e)
        {
            this->v = v;
            this->e = e;
        }
};

template<class datatype> class Network{
	public:
		Graph<datatype> g;
		datatype s, t;
		void setup(Graph<datatype> g, datatype s, datatype t)
		{
			this->g = g;
			this->s = s;
			this->t = t;
		}	
};

template<class datatype> class ford_fulkerson
{
	public:
		void Label(Network<datatype> n)
		{

		}	
		void Augment_Path(Network<datatype> n)
		{

		}	
		ford_fulkerson(Network<datatype> n)
		{

		}
};

int main()
{

	return 0;
}