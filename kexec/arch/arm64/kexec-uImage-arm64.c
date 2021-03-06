/*
 * uImage support added by David Woodhouse <dwmw2@infradead.org>
 */
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <image.h>
#include <kexec-uImage.h>
#include "../../kexec.h"
#include "kexec-arm64.h"

int uImage_arm64_probe(const char *buf, off_t len)
{
	return uImage_probe_kernel(buf, len, IH_ARCH_ARM64);
}

int uImage_arm64_load(int argc, char **argv, const char *buf, off_t len,
	struct kexec_info *info)
{
	struct Image_info img;
	int ret;

	ret = uImage_load(buf, len, &img);
	if (ret)
		return ret;

	return image_arm64_load(argc, argv, img.buf, img.len, info);
}

void uImage_arm64_usage(void)
{
	printf(
"     An ARM64 U-boot uImage file, compressed or not, big or little endian.\n\n");
}
