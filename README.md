# Vision
It is currently unsafe to interact with LLM chatbots over the internet since you are not in control of your data. It is also cost prohibitive to run LLMs locally without sacrificing accuracy due to quantization during inference.

There is a growing interest within the LLM community of using old and affordable yet powerful datacenter cards for running Open Source large language models in a privacy conscious manner locally. The big issue however is that these old cards often need custom compute kernels to be linked against GPGPU compiler libraries that are no longer maintained.

This project aims to make it possible to run open source GPT-3 quality models locally and privately without sacrificing model accuracy(due to quantization) for under $1200. To do this, I have will need to port models such as Falcon 180B and LLama2 to old GPUs such as the Tesla K, M, and P series, as well as the AMD MI25 GPUs.

# Progress
I have been able to get Llama 2 7b running locally without quantization on a $69 Mi25 card. Some notes here: 

# TODO
 - [ ] Split transformer layers for Llama 13b to run across two Mi25
 - [ ] Port BitsAndBytes to ROCm
