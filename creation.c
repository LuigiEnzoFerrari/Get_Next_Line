int		fail_just_fail(BUFFER_SIZE, read_len, fd)
{
	if (BUFFER_SIZE <=0 || read_len > BUFFER_SIZE || read_len < 0 || fd < 0 || fd > RLIMIT_NOFILE)
	return (-1)
}