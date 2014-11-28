#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define DEVURANDOM "/dev/urandom"

static int fd;

void rand_init()
{
	if((fd=open(DEVURANDOM, O_RDONLY))==-1){
		fprintf(stderr, "%s:%d: error: open: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	return;
}

void rand_finalize()
{
	int rc;

	if((rc=close(fd))==-1){
		fprintf(stderr, "%s:%d: error: close: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	return;
}

uint8_t rand8()
{
	uint8_t r;
	ssize_t rc;

	if((rc=read(fd, &r, sizeof(uint8_t)))==-1){
		fprintf(stderr, "%s:%d: error: read: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	return r;
}

uint16_t rand16()
{
	uint16_t r;
	ssize_t rc;

	if((rc=read(fd, &r, sizeof(uint16_t)))==-1){
		fprintf(stderr, "%s:%d: error: read: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	return r;
}

uint32_t rand32()
{
	uint32_t r;
	ssize_t rc;

	if((rc=read(fd, &r, sizeof(uint32_t)))==-1){
		fprintf(stderr, "%s:%d: error: read: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	return r;
}

uint64_t rand64()
{
	uint64_t r;
	ssize_t rc;

	if((rc=read(fd, &r, sizeof(uint64_t)))==-1){
		fprintf(stderr, "%s:%d: error: read: %s\n", __FILE__, __LINE__, strerror(errno));
		exit(EXIT_FAILURE);
	}

	return r;
}
