#include "tentacle.h"
#include "data.h"
using namespace DATA;
Tentacle::Tentacle(TId source, TId target) :
	Object(), m_sourceStudent(source), m_targetStudent(target),
	m_length(getDistance(Data::students[source].getPos(), Data::students[target].getPos()))
{
	m_resource = 0;
	m_backResource = 0;
	m_frontResource = 0;
	m_status = Extending;
	if(Data::students[target].)
}
