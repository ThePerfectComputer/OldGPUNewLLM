#include <hip/hip_runtime.h>
#include <iostream>

const int N = 256;

__global__ void vectorAdd(float *a, float *b, float *c) {
    int idx = hipBlockIdx_x * hipBlockDim_x + hipThreadIdx_x;
    if (idx < N) {
        c[idx] = a[idx] + b[idx];
    }
}

int main() {
    float *h_a = new float[N];
    float *h_b = new float[N];
    float *h_c = new float[N];

    // Initialize host arrays
    for (int i = 0; i < N; i++) {
        h_a[i] = static_cast<float>(i);
        h_b[i] = static_cast<float>(N - i);
    }

    float *d_a, *d_b, *d_c;
    hipMalloc(&d_a, N * sizeof(float));
    hipMalloc(&d_b, N * sizeof(float));
    hipMalloc(&d_c, N * sizeof(float));

    hipMemcpy(d_a, h_a, N * sizeof(float), hipMemcpyHostToDevice);
    hipMemcpy(d_b, h_b, N * sizeof(float), hipMemcpyHostToDevice);

    const int threadsPerBlock = 64;
    const int blocks = (N + threadsPerBlock - 1) / threadsPerBlock;

    hipLaunchKernelGGL(vectorAdd, dim3(blocks), dim3(threadsPerBlock), 0, 0, d_a, d_b, d_c);

    hipMemcpy(h_c, d_c, N * sizeof(float), hipMemcpyDeviceToHost);

    // Print the result
    for (int i = 0; i < N; i++) {
        std::cout << h_a[i] << " + " << h_b[i] << " = " << h_c[i] << std::endl;
    }

    // Cleanup
    delete[] h_a;
    delete[] h_b;
    delete[] h_c;
    hipFree(d_a);
    hipFree(d_b);
    hipFree(d_c);

    return 0;
}
