from argparse import ArgumentParser
import hid


def open(vid, pid, itf=-1):
    infos = hid.enumerate(vid=vid, pid=pid)
    vendor_info = None

    print("Found interfaces:")
    print(infos)

    for info in infos:
        if info["interface_number"] == itf:
            vendor_info = info
            break

    assert vendor_info is not None

    dev = hid.Device(path=vendor_info["path"])

    return dev


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument("--itf", type=int, default=1)
    parser.add_argument("--vid", default="0x5BD")
    parser.add_argument("--pid", default="0x3104")

    args = parser.parse_args()
    vid = int(args.vid, 0)
    pid = int(args.pid, 0)
    itf = args.itf

    print("Open vid=0x%04x pid=%04x itf=%d..." % (vid, pid, itf), end="", flush=True)

    hid_device = open(vid=vid, pid=pid, itf=itf)

    print("OK", flush=True)

    test_data = b"Just some testdata 12345."

    req = test_data + bytes([0] * (64 - len(test_data)))

    print(
        "Write some testdata and wait for response (%d bytes)..." % len(req),
        end="",
        flush=True,
    )

    hid_device.write(req)

    resp = hid_device.read(64, timeout=2 * 1000)
    print(resp)
