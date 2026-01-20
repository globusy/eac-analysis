char __fastcall allocate_140068BD4(__int64 process, __int64 allocate_structure)
{
  char v2; // bp
  int m_protect_check; // eax
  int m_protect; // ebx
  int m_allocation_type; // edi
  __int64 m_zero_bits; // rsi
  unsigned __int64 v9; // rax
  __int64 (__fastcall **allocate_virtual_memory)(__int64, __int64 *, __int64, __int64 *, int, int); // rax
  int allocate_result; // ebx
  _BYTE v13[16]; // [rsp+30h] [rbp-68h] BYREF
  _BYTE v14[88]; // [rsp+40h] [rbp-58h] BYREF
  __int64 m_address; // [rsp+A0h] [rbp+8h] BYREF
  __int64 m_region_size; // [rsp+B0h] [rbp+18h] BYREF

  v2 = 0;
  if ( !process )
    return 0;
  if ( !allocate_structure )
    return 0;
  if ( !*(_QWORD *)(allocate_structure + 24) )
    return 0;
  if ( !*(_DWORD *)(allocate_structure + 32) )
    return 0;
  m_protect_check = *(_DWORD *)(allocate_structure + 36);
  if ( !m_protect_check || (m_protect_check & 0xF0) != 0 || *(_QWORD *)(allocate_structure + 8) )
    return 0;
  if ( attach_process_14003CE18(process, (__int64)v14) )
  {
    m_protect = *(_DWORD *)(allocate_structure + 36);
    m_allocation_type = *(_DWORD *)(allocate_structure + 32);
    m_zero_bits = *(_QWORD *)(allocate_structure + 16);
    m_address = *(_QWORD *)(allocate_structure + 8);
    m_region_size = *(_QWORD *)(allocate_structure + 24);
    v9 = decrypt_ptr_14002D81C(qword_1402097B0);
    allocate_virtual_memory = (__int64 (__fastcall **)(__int64, __int64 *, __int64, __int64 *, int, int))sub_14000F4B4((__int64)v13, __ROR8__(~v9, 17) ^ 0xAB1276D877943869uLL);
    allocate_result = (*allocate_virtual_memory)(
                        -1,
                        &m_address,
                        m_zero_bits,
                        &m_region_size,
                        m_allocation_type,
                        m_protect);
    sub_14000F4A0((__int64)v13);
    if ( allocate_result >= 0 )
    {
      v2 = 1;
      *(_QWORD *)(allocate_structure + 8) = m_address;
      *(_QWORD *)(allocate_structure + 24) = m_region_size;
    }
    sub_14003D0AC(process, (__int64)v14);
  }
  return v2;
}
