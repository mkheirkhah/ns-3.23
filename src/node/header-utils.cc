/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2006 INRIA
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Mathieu Lacage <mathieu.lacage@sophia.inria.fr>
 */
#include "header-utils.h"

namespace ns3 {

void WriteTo (Buffer::Iterator &i, Ipv4Address ad)
{
  i.WriteHtonU32 (ad.GetHostOrder ());
}
void WriteTo (Buffer::Iterator &i, MacAddress ad)
{
  uint8_t mac[MacAddress::MAX_LEN];
  ad.Peek (mac);
  i.Write (mac, ad.GetLength ());
}

void ReadFrom (Buffer::Iterator &i, Ipv4Address &ad)
{
  ad.SetHostOrder (i.ReadNtohU32 ());
}
void ReadFrom (Buffer::Iterator &i, MacAddress &ad, uint32_t len)
{
  uint8_t mac[MacAddress::MAX_LEN];
  i.Read (mac, len);
  ad.Set (mac);
}



}; // namespace ns3
