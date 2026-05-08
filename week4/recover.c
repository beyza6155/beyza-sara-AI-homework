// TODO 3: Declare your variables
    BYTE buffer[512];
    int count = 0;
    FILE *img = NULL;
    char filename[8];

    // TODO 4: Main loop — read one 512-byte block at a time
    while (fread(buffer, 1, 512, card) == 512)
    {
        // STEP A: Check if this block starts a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe 0)
        {
            // STEP B: If we already have an open file, close it
            // We found a new header, so the previous photo must be finished
            if (img != NULL)
            {
                fclose(img);
            }

            // STEP C: Open a new output file
            // Generate name like "000.jpg", "001.jpg", etc.
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "wb");
            count++;
        }

        // STEP D: If we currently have an open output file, write the block
        // This handles both the first block (the header) and all subsequent "body" blocks
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // TODO 5: Close any remaining open file and close the card
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
