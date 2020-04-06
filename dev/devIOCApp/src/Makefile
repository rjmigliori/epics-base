TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = devIOC
# devIOC.dbd will be created and installed
DBD += devIOC.dbd

# devIOC.dbd will be made up from these files:
devIOC_DBD += base.dbd

# Include dbd files from all support applications:
#devIOC_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#devIOC_LIBS += xxx

# devIOC_registerRecordDeviceDriver.cpp derives from devIOC.dbd
devIOC_SRCS += devIOC_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
devIOC_SRCS_DEFAULT += devIOCMain.cpp
devIOC_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#devIOC_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
devIOC_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

