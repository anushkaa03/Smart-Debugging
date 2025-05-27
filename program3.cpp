void memoryLeak() {
    int* ptr = new int[10];  // ⚠️ No delete → memory leak
}
