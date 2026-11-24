#define DR_MP3_IMPLEMENTATION
#include "dr_libs/dr_mp3.h"
#include "mp3_loader.h"

bool load_mp3(const std::string &filename, std::vector<float> &interleaved,
              unsigned int &channels, unsigned long long &frames,
              unsigned int &sample_rate) {
  drmp3_config config;
  drmp3_uint64 frame_count = 0;
  float *pcm = drmp3_open_file_and_read_pcm_frames_f32(filename.c_str(), &config,
                                                       &frame_count, NULL);
  if (pcm == NULL || frame_count == 0 || config.channels == 0) {
    if (pcm) drmp3_free(pcm, NULL);
    return false;
  }
  channels = config.channels;
  sample_rate = config.sampleRate;
  frames = frame_count;
  interleaved.assign(pcm, pcm + frame_count * config.channels);
  drmp3_free(pcm, NULL);
  return true;
}
