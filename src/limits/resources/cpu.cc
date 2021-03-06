#include <string>
#include <fmt/core.h>
#include "ssandbox/cgroup.h"
#include "ssandbox/limits/resource.h"

void ssandbox::limits_manager::cpu(unsigned int limit) {
    auto cs = ssandbox::cgroup_subsystem("cpu");
    auto c = cs.create(fmt::format("ssandbox_{}", this->_uid));

    c->write("cpu.cfs_period_us", "1000000");
    c->write("cpu.cfs_quota_us", std::to_string(limit * 10000));
    c->write("tasks", std::to_string(this->_pid));

    this->_used_cgroup.push_back(c);
}
