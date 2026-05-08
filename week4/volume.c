// TODO 5: Read each audio sample, scale it, and write it out
    int16_t sample;
    
    // fread returns the number of items successfully read. 
    // It will return 1 until it hits the end of the file.
    while (fread(&sample, sizeof(int16_t), 1, input) == 1)
    {
        // Multiply the current sample by the volume factor
        // We cast it back to int16_t to ensure it fits the original data type
        sample = (int16_t)(sample * factor);

        // Write the modified sample to the output file
        fwrite(&sample, sizeof(int16_t), 1, output);
    }
