import React from "react";
import { Box, Stack, Typography } from "@mui/material";
import Logo from "../assets/images/Logo-1.png";

const Footer = () => (
  <Box mt="80px" bgcolor="#FFF3F4">
    <Stack
      gap="40px"
      sx={{ alignItems: "center" }}
      flexWrap="wrap"
      px="35px"
      pt="20px"
    >
      <img src={Logo} alt="logo" style={{ width: "200px", height: "38px" }} />
    </Stack>
    <Typography
      variant="h5"
      sx={{ fontSize: { lg: "25px", xs: "18px" } }}
      mt="41px"
      textAlign="center"
      pb="40px"
    >
      Made with ❤️ by Aniket
    </Typography>
  </Box>
);

export default Footer;
