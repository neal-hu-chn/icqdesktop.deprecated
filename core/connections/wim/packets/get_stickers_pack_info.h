#ifndef __GET_STICKERS_PACK_INFO_H_
#define __GET_STICKERS_PACK_INFO_H_

#pragma once

#include "../wim_packet.h"

namespace core
{
    namespace tools
    {
        class http_request_simple;
    }
}

namespace core
{
    namespace tools
    {
        class binary_stream;
    }

    namespace wim
    {
        class get_stickers_pack_info_packet : public wim_packet
        {
            const int32_t pack_id_;

            const std::string store_id_;

            const std::string file_id_;

            std::shared_ptr<core::tools::binary_stream> response_;

            virtual int32_t init_request(std::shared_ptr<core::http_request_simple> _request) override;

            virtual int32_t parse_response(std::shared_ptr<core::tools::binary_stream> _response) override;

        public:

            bool support_async_execution() const override;

            get_stickers_pack_info_packet(wim_packet_params _params, const int32_t _pack_id, const std::string& _store_id, const std::string& _file_id);
            virtual ~get_stickers_pack_info_packet();

            std::shared_ptr<core::tools::binary_stream> get_response() const;

        };
    }
}

#endif //__GET_STICKERS_PACK_INFO_H_
