import hid


def open(vid, pid, itf=-1):
    infos = hid.enumerate(vid=vid, pid=pid)
    vendor_info = None

    # print(infos)

    for info in infos:
        if info["interface_number"] == itf:
            vendor_info = info
            break

    assert vendor_info is not None

    dev = hid.Device(path=vendor_info["path"])

    return dev


if __name__ == "__main__":
    hid_device = open(vid=0x05BD, pid=0x3104, itf=1)

    test_data = b"Just some testdata 12345."

    req = test_data + bytes([0] * (64 - len(test_data)))

    hid_device.write(req)

    resp = hid_device.read(64, timeout=2 * 1000)
    print(resp)
