char __fastcall allocate_140068BD4(__int64 a1, __int64 a2)
{
  char result; // bp
  int m_protect_check; // eax
  int m_protect; // ebx
  int m_allocation_type; // edi
  __int64 m_zero_bits; // rsi
  __int64 v9; // rax
  __int64 (__fastcall **allocate_virtual_memory)(__int64, __int64 *, __int64, __int64 *, int, int); // rax
  int allocate_result; // ebx
  _BYTE v13[16]; // [rsp+30h] [rbp-68h] BYREF
  _BYTE v14[88]; // [rsp+40h] [rbp-58h] BYREF
  __int64 m_address; // [rsp+A0h] [rbp+8h] BYREF
  __int64 m_region_size; // [rsp+B0h] [rbp+18h] BYREF

  result = 0;
  if ( !a1 )
    return 0;
  if ( !a2 )
    return 0;
  if ( !*(_QWORD *)(a2 + 24) )
    return 0;
  if ( !*(_DWORD *)(a2 + 32) )
    return 0;
  m_protect_check = *(_DWORD *)(a2 + 36);
  if ( !m_protect_check || (m_protect_check & 0xF0) != 0 || *(_QWORD *)(a2 + 8) )
    return 0;
  if ( (unsigned __int8)attach_process_14003CE18(a1, v14) )
  {
    m_protect = *(_DWORD *)(a2 + 36);
    m_allocation_type = *(_DWORD *)(a2 + 32);
    m_zero_bits = *(_QWORD *)(a2 + 16);
    m_address = *(_QWORD *)(a2 + 8);
    m_region_size = *(_QWORD *)(a2 + 24);
    v9 = decrypt_ptr_14002D81C(&unk_1402097B0);
    allocate_virtual_memory = (__int64 (__fastcall **)(__int64, __int64 *, __int64, __int64 *, int, int))sub_14000F4B4(v13, __ROR8__(~v9, 17) ^ 0xAB1276D877943869uLL);
    allocate_result = (*allocate_virtual_memory)(
                        -1,
                        &m_address,
                        m_zero_bits,
                        &m_region_size,
                        m_allocation_type,
                        m_protect);
    sub_14000F4A0(v13);
    if ( allocate_result >= 0 )
    {
      result = 1;
      *(_QWORD *)(a2 + 8) = m_address;
      *(_QWORD *)(a2 + 24) = m_region_size;
    }
    sub_14003D0AC(a1, v14);
  }
  return result;
}
