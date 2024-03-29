import styled from "styled-components";

export const StyledHeader = styled.header`
  background-color: ${({ theme }) => theme.color.header};
  padding: 40px 0;
`;

export const Nav = styled.nav`
  display: flex;
  align-items: center;
  justify-content: space-between;
  margin-bottom: 40px;
  @media (max-width: ${({ theme }) => theme.mobile}) {
    flex-direction: column;
  }
`;

export const Logo = styled.img`
  padding: 10px;
  @media (max-width: ${({ theme }) => theme.mobile}) {
    margin-bottom: 40px;
  }
`;
export const Image = styled.img`
  width: 375px;
  margin-left: 40px;
  @media (max-width: ${({ theme }) => theme.mobile}) {
    margin: 40px 0 30px;
  }
`;
