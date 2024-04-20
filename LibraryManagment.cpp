

#include "LibraryManagment.h"

std::string genreToString(Genre genre) {
    switch (genre) {
        case Genre::Fiction:
            return "Fiction";
        case Genre::NonFiction:
            return "Non-Fiction";
        case Genre::Mystery:
            return "Mystery";
        case Genre::Romance:
            return "Romance";
        case Genre::ScienceFiction:
            return "Science Fiction";
        case Genre::Biography:
            return "Biography";
        case Genre::History:
            return "History";
        case Genre::Poetry:
            return "Poetry";
        case Genre::Philosophy:
            return "Philosophy";
        case Genre::Other:
            return "Other";
        default:
            return "Unknown";
    }
}

std::string genreToString(int genre) {
    switch (genre) {
        case Genre::Fiction:
            return "Fiction";
        case Genre::NonFiction:
            return "Non-Fiction";
        case Genre::Mystery:
            return "Mystery";
        case Genre::Romance:
            return "Romance";
        case Genre::ScienceFiction:
            return "Science Fiction";
        case Genre::Biography:
            return "Biography";
        case Genre::History:
            return "History";
        case Genre::Poetry:
            return "Poetry";
        case Genre::Philosophy:
            return "Philosophy";
        case Genre::Other:
            return "Other";
        default:
            return "Unknown";
    }
}
