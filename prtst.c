#pragma pack(1)
struct s_frob {
    char a;
    long b;
} frob;

#pragma pack (0)

int fred()
{
    return sizeof(frob);
}
