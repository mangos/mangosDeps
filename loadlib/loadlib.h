/**
 * This code is part of MaNGOS. Contributor & Copyright details are in AUTHORS/THANKS.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef LOAD_LIB_H
#define LOAD_LIB_H

#include "StormLib.h"
#include <cstdint>
#include <string>
#include <deque>
#include <map>

#ifndef _WIN32
using HANDLE = void*;
#endif

using int8   = int8_t;
using int16  = int16_t;
using int32  = int32_t;
using int64  = int64_t;
using uint8  = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
using uint64 = uint64_t;


using ArchiveSet = std::deque<HANDLE>;
using ArchiveSetBounds = std::pair<ArchiveSet::const_iterator, ArchiveSet::const_iterator>;


/**
* @brief Open a MPQ file archive and return the Archive HANDLE to the calling method.
* @details Open an MPQ file archive and pushes to the list of opened archives.
*  Use this method by opening the MPQ in their priority order, from the lowest to the highest priority.
* @param[in] mpqFileName The location of the MPQ, including its filename.
* @param[out] mpqHandlePtr A pointer to the handle to be retrieved.
*
* @pre The mpqFileName must point to an existing MPQ file.
*
* @returns `true` if the Archive has been opened successfully, `false` otherwise.
*/
bool OpenArchive(char const* mpqFileName, HANDLE* mpqHandlePtr = NULL);

/**
* @brief Open a file from an already opened MPQ file archive. Returns a handler to the requested file.
* @details Open a file, given the filename, from an already opened MPQ file archive.
* This method will take the opened archived depending on their priority. If A.mpq was opened before B.mpq and a the file exists within both
* archives, the handle will point to the file contained in the archive B.mpq as it has the highest priority.
* @param[in] filename The filename to be retrieved.
* @param[in, out] fileHandlerPtr A pointer to the handle to be retrieved.
*
* @pre The filename must exist within at least one opened MPQ archive.
*
* @returns `true` if the file has been found in at least one archive, `false` otherwise.
*/
bool OpenNewestFile(char const* filename, HANDLE* fileHandlerPtr);

/**
* TODO
*/
ArchiveSetBounds GetArchivesBounds();

/**
* @brief Extract a file from a given MPQ file archive.
* @details Extract a file from a given MPQ file archive to the filesystem.
* This method will take the opened archived depending on their priority. If A.mpq was opened before B.mpq and a the file exists within both
* archives, the extract file will be the one contained in the archive B.mpq as it has the highest priority.
* @param[in] mpq_name The location of the MPQ file archive to open.
* @param[in] filename The filename to be extracted from the MPQ.
*/
bool ExtractFile(char const* mpq_name, std::string const& filename);

/**
* @brief Closed all handlers to MPQ file archives.
*/
void CloseArchives();

#define FILE_FORMAT_VERSION    18

union u_map_fcc
{
    char   fcc_txt[4];
    uint32 fcc;
};

//
// File version chunk
//
struct file_MVER
{
    union
    {
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    uint32 ver;
};

class FileLoader
{
        uint8*  data;
        uint32  data_size;
    public:
        virtual bool prepareLoadedData();
        uint8* GetData()     {return data;}
        uint32 GetDataSize() {return data_size;}

        file_MVER* version;
        FileLoader();
        ~FileLoader();
        bool loadFile(char* filename, bool log = true);
        virtual void free();
};

/**************************************
    Required for MoP data extraction
    ================================
 **************************************/
class FileChunk
{
public:
    ~FileChunk();

    uint8* data;
    uint32 size;

    template<class T>
    T* As() { return (T*)data; }
    void parseSubChunks();
    std::multimap<std::string, FileChunk*> subchunks;
    FileChunk* GetSubChunk(std::string const& name);
};

class ChunkedFile{
public:
    uint8  *data;
    uint32  data_size;
    uint8 *GetData()     {return data;}
    uint32 GetDataSize() {return data_size;}

    ChunkedFile();
    virtual ~ChunkedFile();
    bool prepareLoadedData();
    bool loadFile(HANDLE mpq, char *filename, bool log = true);
    void free();

    void parseChunks();
    std::multimap<std::string, FileChunk*> chunks;
    FileChunk* GetChunk(std::string const& name);
};
#endif