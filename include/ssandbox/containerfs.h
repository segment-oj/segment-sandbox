// -*- C++ -*- Part of the Segment Sandbox Project

#ifndef CONTAINERFS_H
#define CONTAINERFS_H

#include <filesystem>
#include <memory>
#include <sys/mount.h>

namespace ssandbox {

struct MountInfo {
    /* will be mount to here in you host machine */
    std::filesystem::path point;
    /* Mount source in your host machine (Lower Directory) */
    std::filesystem::path lower_dir;
    /* Temp Working Dir for overlay */
    std::filesystem::path workspace;
    /* Upper Directory */
    std::filesystem::path upper_dir;

    /* An extra point to mount, will be mounted into /mnt inside container*/
    std::filesystem::path extra_point;

    /* If enabled, it will mount /proc */
    bool mount_proc;

    /* If enabled, it will mount /tmp */
    bool mount_tmp;
};

class AbstructContainerFS {
public:
    void mountAll();
    void enableTmp(bool enable = true);
    void enableProc(bool enable = true);
    void setUID(std::string uid);
    void setWorkspace(std::filesystem::path workspace_path);

protected:
    virtual void mountMain() = 0;
    virtual void mountExtra() = 0;
    
    std::string uid;
    std::filesystem::path workspace;

private:
    void mountTmp();
    void mountProc();

    bool _mount_tmp;
    bool _mount_proc;
};

void mount_containerfs(MountInfo cfg);
void umount_containerfs(MountInfo cfg);

} /* namespace ssandbox */

#endif /* CONTAINERFS_H */