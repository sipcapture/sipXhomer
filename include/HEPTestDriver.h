#ifndef HEPTESTDRIVER_H
#define	HEPTESTDRIVER_H

#include "HEPCaptureAgent.h"

class HEPTestDriver
{
public:
  HEPTestDriver(HEPCaptureAgent& agent);
  ~HEPTestDriver();
  bool runTests();

protected:
  HEPCaptureAgent& _agent;
};


#endif	/* HEPTESTDRIVER_H */

