// Copyright (c) 2012 eZuce, Inc. All rights reserved.
// Contributed to SIPfoundry under a Contributor Agreement
//
// This software is free software; you can redistribute it and/or modify it under
// the terms of the Affero General Public License (AGPL) as published by the
// Free Software Foundation; either version 3 of the License, or (at your option)
// any later version.
//
// This software is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more
// details.

#ifndef HEPCAPTUREAGENT_H
#define	HEPCAPTUREAGENT_H

#include "sqa/ServiceOptions.h"
#include "sqa/sqaclient.h"
#include "sipxhomer/HEPMessage.h"
#include "sipxhomer/HEPDao.h"
#include <boost/thread.hpp>

class HEPCaptureAgent
{
public:
  HEPCaptureAgent(ServiceOptions& options, HEPDao& dao);
  ~HEPCaptureAgent();
  void run();
  void stop();
  void onReceivedEvent(HEPMessage& event);
  ServiceOptions& options();
private:
  void internalRun();
  ServiceOptions& _options;
  SQAWatcher* _pWatcher;
  HEPDao& _dao;
  bool _isRunning;
  boost::thread* _pRunThread;
};


//
// Inlines
//

inline ServiceOptions& HEPCaptureAgent::options()
{
  return _options;
}

#endif	/* HEPCAPTUREAGENT_H */

