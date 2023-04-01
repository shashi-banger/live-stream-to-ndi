#include <libavutil/pixfmt.h>

#include <memory>
#include <vector>
#include <map>

struct AVFrame;
struct AVPacket;
struct AVFilterContext;
struct AVCodecContext;
struct AVDictionary;

namespace ffmpeg {

std::shared_ptr<AVFrame>  alloc_frame();
std::shared_ptr<AVPacket> alloc_packet();

AVDictionary*                      to_dict(std::map<std::string, std::string>&& map);
std::map<std::string, std::string> to_map(AVDictionary** dict);

} // namespace ffmpeg
