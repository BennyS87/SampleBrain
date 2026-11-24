// MP3 decoding via dr_mp3 (public domain / MIT-0, brain/src/dr_libs)
#pragma once
#include <string>
#include <vector>

// Decodes an MP3 file to interleaved float samples.
// Returns false if the file can't be opened or isn't an MP3.
bool load_mp3(const std::string &filename, std::vector<float> &interleaved,
              unsigned int &channels, unsigned long long &frames,
              unsigned int &sample_rate);
