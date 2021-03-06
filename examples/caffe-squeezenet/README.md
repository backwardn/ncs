# SqueezeNet graph example

Example in this directory uses [SqueezeNet](https://arxiv.org/abs/1602.07360) caffe model to classify the following image of an acoustic guitar:

<img src="./nps_acoustic_guitar.png" alt="acoustic guitar" width="227">

## Prerequisites

Install [GoCV](https://github.com/hybridgroup/gocv/#how-to-install).

This example uses C/C++ NCSDK 2.0, so make sure you have it installed by following the instructions [here](https://movidius.github.io/ncsdk/install.html)

Note, since the 2.0 API does not seem to work properly on macOS, you won't be able to run this example on macOS. Everything works fine on Linux, in particular this example was tested on `Ubuntu 16.04`

## Running the example

Note, the example program contains hardcoded paths to the compiled Movidius graph file, the image of acoustic guitar and the SqueezeNet labels.

You can run this example as follows:

```console
go run main.go
```

Result:

```console
2018/08/28 13:48:24 Attempting to create NCS device handle
2018/08/28 13:48:24 NCS device handle successfully created
2018/08/28 13:48:24 Attempting to open NCS device
2018/08/28 13:48:28 NCS device successfully opened
2018/08/28 13:48:28 Attempting to create NCS graph handle
2018/08/28 13:48:28 NCS graph handle successfully created
2018/08/28 13:48:28 Attempting to allocate NCS graph
2018/08/28 13:48:28 NCS Graph successfully allocated
2018/08/28 13:48:28 Attempting to read image nps_acoustic_guitar.png
2018/08/28 13:48:28 Attempting to queue nps_acoustic_guitar.png for inference
2018/08/28 13:48:28 nps_acoustic_guitar.png successfully queued for inference
2018/08/28 13:48:28 Attempting to read data from NCS
2018/08/28 13:48:28 Read suceeded. Read 4000 bytes
2018/08/28 13:48:28 Reading labels file: squeeze_synset_words.txt
2018/08/28 13:48:28 Read 1000 labels from squeeze_synset_words.txt
2018/08/28 13:48:28 Prediction: n02676566 acoustic guitar, Probability: 0.99316406
```
