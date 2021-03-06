#include "ncs.h"
#include <stdio.h>

int ncs_DeviceCreate(int idx, void** deviceHandle) {
    ncStatus_t s = ncDeviceCreate(idx, (struct ncDeviceHandle_t**) deviceHandle);
    return int(s);
}

int ncs_DeviceOpen(void* deviceHandle) {
    ncStatus_t s = ncDeviceOpen((struct ncDeviceHandle_t*) deviceHandle);
    return int(s);
}

int ncs_DeviceGetOption(void* deviceHandle, int option, void *data, unsigned int *dataLength) {
        ncStatus_t s = ncDeviceGetOption((struct ncDeviceHandle_t*) deviceHandle, option, data, dataLength);
        return int(s);
}

int ncs_DeviceClose(void* deviceHandle) {
    ncStatus_t s = ncDeviceClose((struct ncDeviceHandle_t*) deviceHandle);
    return int(s);
}

int ncs_DeviceDestroy(void** deviceHandle) {
    ncStatus_t s = ncDeviceDestroy((struct ncDeviceHandle_t**) deviceHandle);
    return int(s);
}

int ncs_GraphCreate(const char* name, void** graphHandle) {
        ncStatus_t s = ncGraphCreate(name, (struct ncGraphHandle_t**) graphHandle);
        return int(s);
}

int ncs_GraphAllocate(void* deviceHandle, void* graphHandle, const void *graphBuffer, unsigned int graphBufferLength) {
        ncStatus_t s = ncGraphAllocate((struct ncDeviceHandle_t*) deviceHandle, (struct ncGraphHandle_t*) graphHandle,
                        graphBuffer, graphBufferLength);
        return int(s);
}

int ncs_GraphAllocateWithFifos(void* deviceHandle, void* graphHandle, const void *graphBuffer, unsigned int graphBufferLength, void** inFifoHandle, void** outFifoHandle) {
        int s = ncs_GraphAllocateWithFifosEx(deviceHandle,
                        graphHandle, graphBuffer, graphBufferLength,
                        inFifoHandle, NC_FIFO_HOST_WO, 2, NC_FIFO_FP32,
                        outFifoHandle, NC_FIFO_HOST_RO, 2, NC_FIFO_FP32);

        return int(s);
}


int ncs_GraphAllocateWithFifosEx(void* deviceHandle, void* graphHandle, const void *graphBuffer, unsigned int graphBufferLength, void** inFifoHandle, ncFifoType_t inFifoType, int inNumElem, ncFifoDataType_t inDataType, void** outFifoHandle,  ncFifoType_t outFifoType, int outNumElem, ncFifoDataType_t outDataType) {
        ncStatus_t s = ncGraphAllocateWithFifosEx((struct ncDeviceHandle_t*) deviceHandle,
                        (struct ncGraphHandle_t*) graphHandle, graphBuffer, graphBufferLength,
                        (struct ncFifoHandle_t**) inFifoHandle, inFifoType, inNumElem, inDataType,
                        (struct ncFifoHandle_t**) outFifoHandle, outFifoType, outNumElem, outDataType);
        return int(s);
}

int ncs_GraphQueueInference(void* graphHandle, void** inFifoHandle, unsigned int inFifoCount, void** outFifoHandle, unsigned int outFifoCount) {
        ncStatus_t s = ncGraphQueueInference((struct ncGraphHandle_t*) graphHandle,
                        (struct ncFifoHandle_t**) inFifoHandle, inFifoCount,
                        (struct ncFifoHandle_t**) outFifoHandle, outFifoCount);
        return int(s);
}

int ncs_GraphQueueInferenceWithFifoElem(void* graphHandle, void* inFifoHandle, void* outFifoHandle, const void* inputTensor, unsigned int* inputTensorLength, void* userParam) {
        ncStatus_t s = ncGraphQueueInferenceWithFifoElem((struct ncGraphHandle_t*) graphHandle,
                        (struct ncFifoHandle_t*) inFifoHandle,
                        (struct ncFifoHandle_t*) outFifoHandle,
                        inputTensor, inputTensorLength, userParam);
        return int(s);
}

int ncs_GraphGetOption(void* graphHandle, int option, void *data, unsigned int *dataLength) {
        ncStatus_t s = ncGraphGetOption((struct ncGraphHandle_t*) graphHandle, option, data, dataLength);
        return int(s);
}

int ncs_GraphDestroy(void** graphHandle) {
        ncStatus_t s = ncGraphDestroy((struct ncGraphHandle_t**) graphHandle);
        return int(s);
}

int ncs_FifoCreate(const char* name, ncFifoType_t type, void** fifoHandle) {
        ncStatus_t s = ncFifoCreate(name, type, (struct ncFifoHandle_t**) fifoHandle);
        return int(s);
}

int ncs_FifoAllocate(void* fifoHandle, void* deviceHandle, struct ncTensorDescriptor_t* tensorDesc, unsigned int numElem) {
        ncStatus_t s = ncFifoAllocate((struct ncFifoHandle_t*) fifoHandle, (struct ncDeviceHandle_t*) deviceHandle,
                        (struct ncTensorDescriptor_t*) tensorDesc, numElem);
        return int(s);
}
int ncs_FifoGetOption(void* fifoHandle, int option, void *data, unsigned int *dataLength) {
        ncStatus_t s = ncFifoGetOption((struct ncFifoHandle_t*) fifoHandle, option, data, dataLength);
        return int(s);
}

int ncs_FifoWriteElem(void* fifoHandle, const void *inputTensor, unsigned int* inputTensorLength, void* userParam) {
        ncStatus_t s = ncFifoWriteElem((struct ncFifoHandle_t*) fifoHandle, inputTensor, inputTensorLength, userParam);
        return int(s);
}

int ncs_FifoReadElem(void* fifoHandle, void *outputData, unsigned int* outputDataLen, void **userParam) {
        ncStatus_t s = ncFifoReadElem((struct ncFifoHandle_t*) fifoHandle, outputData, outputDataLen, userParam);
        return int(s);
}

int ncs_FifoDestroy(void** fifoHandle) {
        ncStatus_t s = ncFifoDestroy((struct ncFifoHandle_t**) fifoHandle);
        return int(s);
}
