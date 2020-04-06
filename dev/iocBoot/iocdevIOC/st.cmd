#!../../bin/linux-arm/devIOC

## You may have to change devIOC to something else
## everywhere it appears in this file

#< envPaths

## Register all support components
dbLoadDatabase("../../dbd/devIOC.dbd",0,0)
devIOC_registerRecordDeviceDriver(pdbbase) 

## Load record instances
dbLoadRecords("../../db/devIOC.db","user=rmigliori")

iocInit()

## Start any sequence programs
#seq sncdevIOC,"user=rmigliori"
